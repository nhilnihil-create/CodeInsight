#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    long long int h,w;
    cin >> h >> w;

    if(h==1 ||  w ==1){
        cout << 1 << endl;
    }
    else{
        cout << h*w -(h*w/2) << endl;
    }
}
        
