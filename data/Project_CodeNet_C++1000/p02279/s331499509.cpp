#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

std::vector<int> v[100005];
struct Data
{
    int parent_index, depth;
    std::string type;
};
std::map<int, Data> data;
void dfs(const int index, const int parent_index, const int depth)
{
    int size = v[index].size();
    
    Data d;
    d.parent_index = parent_index;
    d.depth = depth;
    if(d.parent_index == -1) d.type = "root";
    else if(size == 1) d.type = "leaf";  // 接点が親だけ
    else d.type = "internal node";
    data[index] = d;
    
    for(int i=0; i<size; i++){
        int child = v[index][i];
        if(child == parent_index) continue;
        dfs(child, index, depth+1);
    }
}

int main()
{
    int n;
    cin >> n;
    std::vector<int> childlist;
    for(int i=0; i<n; i++){
        int id, k, c;
        cin >> id >> k;
        for(int j=0; j<k; j++){
            cin >> c;
            v[id].push_back(c);
            v[c].push_back(id);
            childlist.push_back(c);  // root検索用
        }
    }
    int root = -1;
    for(int i=0; i<n; i++){
        std::vector<int>::iterator itr;
        itr = std::find(childlist.begin(), childlist.end(), i);
        if(itr == childlist.end()){
            root = i;
        }
    }
    if(root == -1) cout << "root not found." << endl;
    dfs(root, -1, 0);
    
    for(int index=0; index<n; index++){
        
        Data d = data[index];
        cout << "node " << index << ": parent = " << d.parent_index
            << ", depth = " << d.depth << ", " << d.type << ", [";
        
        int size = v[index].size();
        if(index != root){
            std::vector<int>::iterator itr;
            itr = find(v[index].begin(), v[index].end(), d.parent_index);
            v[index].erase(itr); size--;
        }
        for(int i=0; i<size; i++){
            int child = v[index][i];
            //if(child == d.parent_index) continue;
            cout << child;
            if(i != size-1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

