
#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=(n);++i)
using namespace std;
using ll=long long;
using P =pair<int,int>;

int main(){
int n;
int count=0;
cin>>n;
rep(i,n){
if(i<100000&&i>=10000){
count++;
}else if(i<10000&&i>=1000){

}else if(i<1000&&i>=100){
    count++;
}else if(i<100&&i>=10){
    
}else if(i<10){
    count++;
}

}
cout<<count;
}