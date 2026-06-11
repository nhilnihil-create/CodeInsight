#include <bits/stdc++.h>
using namespace std;
std::vector<int> v;
int INF= 0x3f3f3f3f;
int mina=INF;
void solve(){
     int N;
     cin >> N;
     for(int i=0;i<N;i+=1){
          int x;
          cin >> x; 
          v.push_back(x);
     }
     int pointer = floor(0);
     int left = v[0];
     int right = 0;
     for(int i=1;i<N;i+=1){
          right+=v[i];
     }
     if(abs(right-left)<mina){
          mina = abs(right-left);
     }
     for(int i=1;i<(N-1);i+=1){
          left+=v[i];
          right-=v[i];
          // cout << left << " " << right << endl;
          if(abs(right-left)<mina){
               mina = abs(right-left);
          }
     }
}
int main() {
     solve();
	cout << mina;
}
