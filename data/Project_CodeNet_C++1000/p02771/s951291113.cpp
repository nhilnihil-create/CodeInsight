#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

ll GCD(ll a, ll b){
  if(b==0) return a;
  else return GCD(b, a%b);
}

ll LCM(ll a, ll b){
  if(a<b) swap(a,b);
  return a/GCD(a,b)*b;
}
 
int main(){
  set<int> st;
  for(int i=0; i<3; i++){
    int a;
    cin >> a;
    st.insert(a);
  }
  if(st.size()==2){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
