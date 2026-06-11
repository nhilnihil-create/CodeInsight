#include <iostream>
#include <vector>

using namespace std;

vector<int> M[10000];
vector<int> m[10000];
int mark[10000]={0};

int main(){
  int V;
  int E;
  int s,t;
  cin >> V >> E;
  for(int i=0;i<E;i++){
    cin >> s >> t;
    M[s].push_back(t);
    m[t].push_back(s);
  }

  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      if(m[j].size()==0&&mark[j]!=1){
        mark[j]=1;
        cout << j <<endl;
        for(int k=0;k<M[j].size();k++){
          for(int l=0;l<m[M[j][k]].size();l++){
            if(m[M[j][k]][l]==j){
              m[M[j][k]].erase(m[M[j][k]].begin() + l);
            }
          }
        }
        break;
      }
    }
  }
  return 0;
}