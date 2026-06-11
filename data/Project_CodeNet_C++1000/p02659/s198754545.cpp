#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int a,c;
    float b;
    cin>>a>>b;
    c= round(100*b);
    cout<<(a*c)/100<<endl;
    return 0;
}
