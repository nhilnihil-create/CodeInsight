 #include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
ll x,y;
cin>>x>>y;
if(y%2==0){
if(x*2<=y && y<=x*4) cout<<"Yes"<<endl;
else
cout<<"No"<<endl;

}
else
cout<<"No"<<endl;
}