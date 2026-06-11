#include <iostream>
#include<set>
#define INF 1e8
using namespace std;
int main(void){
    // Your code here!
int n,k;cin>>n>>k;

int count=0;
while(n){
    count++;
    n/=k;
}
cout<<count;

}
