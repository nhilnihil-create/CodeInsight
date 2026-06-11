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

int x,y,way;
double W,H,sum;
scanf("%lf%lf%d%d",&W,&H,&x,&y);



if(x*2==W && y*2==H){
  way=1;
}

else{
way=0;
}

sum=W*H/2;

printf("%f %d\n",sum,way);

}
