#include <iostream>
#include<set>
#define INF 1e8
using namespace std;
int main(void){
    // Your code here!
int n;
cin>>n;

for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(a%2==0 && a%3!=0 && a%5!=0)
        {
            cout<<"DENIED";
            return 0;
        }
}

cout<<"APPROVED";
}
