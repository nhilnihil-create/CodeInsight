#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;
    
    int x[n];
    for(int i=0;i<n;i++) x[i]=i+1;
    //たとえばn==3だとしてもデバックの時にはxの要素は5つになるので注意

    int p[n],q[n];
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>q[i];

    int a,b,count=1;
    do{
        //配列が完全に同一であるかどうかは一つひとつの要素を順に見ていく必要がある
        int count1=0,count2=0;
        for(int i=0;i<n;i++){            
            if(x[i]==p[i]) count1++;
            if(x[i]==q[i]) count2++;
        }
        if(count1==n) a=count;
        if(count2==n) b=count;
        count++;
    }while(next_permutation(x,x+n));

    cout<<abs(a-b)<<endl;
}