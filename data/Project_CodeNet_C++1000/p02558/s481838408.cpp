#include <iostream>
#include <vector>
using namespace std;

class Union_Find {
    
    private:
         vector<int> id, height;
         int cnt;

    public:
    Union_Find(int n) {

        cnt = 0;
        for(int i=0; i<n; i++){
            id.push_back(i);
            height.push_back(1);
        }            
    }   


    bool connected(int a, int b) {
        return root(a) == root(b);
    }

    void unite(int f, int s) {
        
        int root_f = root(f);
        int root_s = root(s);

        if(height[f] <= height[s]){
            id[root_f] = root_s;
            height[root_s] += height[root_f];
        }

        else if(height[f] > height[s]){
            id[root_s] = root_f;
            height[root_f] += height[root_s];
        }
    }

    int count() {
        for(int i=0; i<id.size(); i++)
            if(id[i] == i)
                cnt++;
        return cnt;
    }

    private:

    int root(int i) {

        while(id[i] != i)
        i = id[i];

        return i;
    }

};

int main(){
    int n;
    cin>>n;

    Union_Find uf(n);
    int q;
    cin>>q;

    for(int i=0; i<q; i++){
        
        int t,f,s;
        cin>>t>>f>>s;

        if(!t)
        uf.unite(f,s);

        else{
            if(uf.connected(f,s))
            cout<<"1\n";
            else cout<<"0\n";
        }
    }

    return 0;
}