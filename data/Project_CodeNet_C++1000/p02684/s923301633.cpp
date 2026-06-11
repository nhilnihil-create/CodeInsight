#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int n,k,f=0,fn=0;
    cin>>n>>k;
    vector<int> a(10000000);
    vector<int> b(10000000);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        if(b[f]==0){
            b[f]=1;
            f=a[f]-1;
        }
        else{
            fn=f;
            for(int j=0;j<n;j++){
                fn=a[fn]-1;
                if(fn==f){
                    fn=j+1;
                    break;
                }
            }
            for(int j=0;j<(k-i)%fn;j++){
                f=a[f]-1;
            }
            break;
        }
    }
    cout<<f+1<<endl;
    return 0;
}
