#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<int> v(n, 0);
    set<int> flg;
    for(int i=0; i<m; i++){
        int s, c; cin >> s >> c;
        if(s==1 && c==0 && n!=1){
          cout << "-1" << endl; return 0;
        }         
        if(flg.count(s)==1 && v[s-1]!=c){
            cout << "-1" << endl; return 0;
        }
        v[s-1]=c;
        flg.insert(s);
    }
    if(v[0]==0 && n!=1) v[0]=1;
    for(int i=0; i<n; i++)  cout << v[i];
    cout << endl;
    return 0;
}