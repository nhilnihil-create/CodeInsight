#include<iostream>
#include<cmath>
#include<iomanip>
#include<set>
using namespace std;
int main(){
int n;

cin>>n;

while(n){
    if(n%10==7)
    {
        cout<<"Yes";
        return 0;
    }
    n/=10;
}
cout<<"No";

}