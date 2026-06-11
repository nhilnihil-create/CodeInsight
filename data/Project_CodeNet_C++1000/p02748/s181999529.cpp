#include<bits/stdc++.h>
using namespace std;
int main(){
 int a,b,m;
 cin>>a>>b>>m;
 vector<int> vea(a);
for(int i=0;i<a;i++){
  cin>>vea.at(i);
}
vector<int> veb(b);
for(int i=0;i<b;i++){
  cin>>veb.at(i);
}
float sum=INFINITY;
for(int i=0;i<m;i++){
    int x,y,c;
    cin>>x>>y>>c;
if(vea.at(x-1)+veb.at(y-1)-c<sum){
    sum=vea.at(x-1)+veb.at(y-1)-c;
}
}
sort(vea.begin(), vea.end());
sort(veb.begin(), veb.end());
if(vea.at(0)+veb.at(0)<sum){
    sum=vea.at(0)+veb.at(0);
}
cout<<sum<<endl;

}