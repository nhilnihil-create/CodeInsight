#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    if((y-2*x)%2==0&&(y-2*x)/2>=0&&(4*x-y)%2==0&&(4*x-y)/2>=0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
