#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(),(x).end())
#define ALL(x) x.begin(),x.end()
#define db(x) cout<<#x<<"="<<x<<endl
#define rep(i, n) for(int i = 0; i < n; i++)
#define reps(i, m, n) for(int i = m; i < n; i++)
#define repr(i, m, n) for(int i = m; i >= n; i--)
#define INF (1e9)
#define PI (acos(-1))
using namespace std;
typedef long long ll;



void Main(){

  int N;
  cin >> N;

  rep(i,N-1){
    reps(j,i+1,N){
      int x=i; int y=j;
      int z=x^y;
      rep(k,10){
        if(z>>k&1){
          cout << k+1 <<" ";
          break;
        }
      }
    }
    cout <<"\n";
  }
}


  //-----------------------------------
  int main(){
//    cin.tie(nullptr);
//    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
  }
  //-----------------------------------
