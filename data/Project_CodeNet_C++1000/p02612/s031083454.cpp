#include<iostream>
#include<cmath>
using namespace std;
int main(){
    float n;
    cin>>n;
    cout<<ceil(n/1000)*1000-n<<endl;
    return 0;
}