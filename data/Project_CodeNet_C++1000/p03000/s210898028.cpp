#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;
int main(){

int N,X,i,c=1;

cin >> N >> X;
std::vector<int> L(N+1);

std::vector<int> D(N+1);
D[0]=0;

for(i=1;i<N+1;i++){
  cin >> L[i];

  D[i]=D[i-1]+L[i];

    if(D[i]>X){
    break;
    }
    else{
    c++;
    }


}

cout << c << endl;
}