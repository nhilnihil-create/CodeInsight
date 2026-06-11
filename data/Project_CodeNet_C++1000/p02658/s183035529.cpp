#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int n,now=1;
    cin>>n;
    vector<long long int> a(10000000);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]==0){
            now=0;
            break;
        }
        if(a[i] <=1000000000000000000/now&&now>0){
            now*=a[i];
        }
        else{
            now=-1;
        }
    }
    cout<<now<<endl;

    return 0;
}
