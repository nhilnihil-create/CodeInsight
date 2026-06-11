#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> p(m);
    for(int i = 0;i < m;i++){
          cin >> p[i].first >> p[i].second;
          p[i].first--;
    }
    
    for(int i = 0;i < 1000;i++){
          string s = to_string(i);
          if(s.size() != n){
                continue;
          }
          bool ok = true;
          for(int j = 0;j < m;j++){
                if(s[p[j].first] != p[j].second + '0'){
                      ok = false;
                }
          }
          if(ok){
                cout << s << endl;
                return 0;
          }
    }
    cout << -1 << endl;
}
