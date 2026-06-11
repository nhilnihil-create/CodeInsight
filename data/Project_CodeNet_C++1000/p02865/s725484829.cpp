#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int n;cin>>n;
    if(n%2==0) cout<<n/2-1<<endl;
    else cout<<n/2<<endl;
}