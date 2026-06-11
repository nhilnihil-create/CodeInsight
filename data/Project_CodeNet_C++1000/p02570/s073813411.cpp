#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int d,t,s;
    cin>>d>>t>>s;
    if(d/s<t||((d/s==t)&&(d%s==0))){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
