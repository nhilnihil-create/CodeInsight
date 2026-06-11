#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int used[27],number[27];
int cnt=1;
int ln;
int n,aa=-1,bb=-1,a[10],b[10];
bool compare(int c[],int d[]){
    for(int i=1;i<=n;i++) {
        if(c[i]!=d[i]) return false;
    }
    return true;
}
void permutation(int at,int n){
    if(at==n+1){
        string s="";
        if(compare(number,a)) aa=cnt;
        if(compare(number,b)) bb=cnt;
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=1;
            number[at]=i;
            permutation(at+1,n);
            used[i]=0;
        }
    }
}
int main()
{     
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
   
    permutation(1,n);
    cout<<abs(aa-bb);
    

}
