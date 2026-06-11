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

int W,H,x,y,way;

scanf("%d%d%d%d",&W,&H,&x,&y);



if(x*2==W && y*2==H){
  way=1;
}

else{
way=0;
}

printf("%lf %d\n",double(W)*double(H)/2,way);

}
