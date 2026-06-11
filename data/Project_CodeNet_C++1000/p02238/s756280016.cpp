#include <iostream>
#include <vector>

using namespace std;

void dfs(int v,vector<vector<int>>& vertex, int d[], int f[]);

int cnt = 1;

int main(){
    int n;
    cin >> n;
    int num;
    int tmp2;
    int d[n] = {};
    int f[n] = {};
    vector<vector<int>> vertex;
    vector<int> tmp;
    for(int i=0;i<n;i++){
        cin >> num;
        cin >> num;
        for(int j=0;j<num;j++){
            cin >> tmp2;
            tmp.push_back(tmp2-1);
        }
        vertex.push_back(tmp);
        tmp.clear();
    }
    dfs(0, vertex, d, f);
    for(int i=0;i<n;i++){
        if(d[i]==0){
            dfs(i, vertex, d, f);
        }
    }
    for(int i=0;i<n;i++){
        cout << i+1 << " " <<  d[i] << " " << f[i] << endl;
    }
    return 0;
}

void dfs(int v, vector<vector<int>>& vertex, int d[], int f[]){
    d[v] = cnt++;
    for(int i : vertex[v]){
        if(d[i]==0){
            dfs(i, vertex, d, f);
        }
    }
    f[v] = cnt++;
}
