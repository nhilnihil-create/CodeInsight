#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;

int main(){
    vector<int>a(5);
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    for(int i=0;i<5;i++){
        if(a[i]!=i+1){
            cout<<i+1<<endl;
        }
    }
}
