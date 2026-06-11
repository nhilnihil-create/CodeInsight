#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int x,k,d;
    cin>>x>>k>>d;
    if(x>=0){
        if(x/d>k){
            cout<<x-k*d<<endl;
        }
        else{
            if((k-(x/d))%2==0){
                cout<<x%d<<endl;
            }
            else{
                cout<<d-(x%d)<<endl;
            }
        }
    }
    else{
        x=-x;
        if(x/d>k){
            cout<<x-k*d<<endl;
        }
        else{
            if((k-(x/d))%2==0){
                cout<<x%d<<endl;
            }
            else{
                cout<<d-(x%d)<<endl;
            }
        }

    }
    return 0;
}
