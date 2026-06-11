#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

static const int MAX = 100;
static const long long INFTY = (1LL<<32);

int n;
long long d[MAX][MAX];

void floyd(){
for(int i=0;i<n;i++)
for(int j=0;j<n;j++){
if(d[j][i]==INFTY)continue;
for(int k=0;k<n;k++){
if(d[i][k]==INFTY)continue;
d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
}
}
}

int main(){
int times,a,b,now;

cin>>n>>times;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++){
if(i==j)d[i][j] = 0;
else d[i][j] = INFTY;
}

while(times--){
cin>>a>>b>>now;
d[a][b] = now;
}
floyd();

bool negative = false;

for(int i=0;i<n;i++)
if(d[i][i]<0)negative = true;
if(negative)cout<<"NEGATIVE CYCLE"<<endl;

else{
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(j)cout<<" ";
if(d[i][j]==INFTY)cout<<"INF";
else cout<<d[i][j];
}
cout<<endl;
}
}
return 0;
}

