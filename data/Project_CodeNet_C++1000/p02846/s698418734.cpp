#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;


int main(){

long long t1,t2;
cin>>t1>>t2;

long long a1,a2;
cin>>a1>>a2;

long long b1,b2;
cin>>b1>>b2;

//相対速度:=二人の距離の差で考える。
long long p=t1*(a1-b1);
long long q=t2*(a2-b2);

if(p>0){
    p*=-1;
    q*=-1;
}
if(p+q<0){
    cout<<"0"<<endl;

}
else if(p+q==0){
    cout<<"infinity"<<endl;
}
else {
    long long s=(-p)/(p+q);
    long long t=(-p)%(p+q);

    if(t !=0){
        cout<<s*2+1<<endl;
    }
    else{
        cout<<s*2<<endl;
    }


}



 return 0;
}
/*
1 2
10 10
12 4

1

100 1
101 101
102 1

infinity


12000 15700
3390000000 3810000000
5550000000 2130000000

113

*/