#include <iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#define ll long long
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<=n;i++)
int main(void){
    // Your code here!
string input[3]{"Sunny", "Cloudy", "Rainy"};
string s;
cin>>s;
rep(3){
    if(s==input[i])
        cout<<input[(i+1)%3];
}

}
