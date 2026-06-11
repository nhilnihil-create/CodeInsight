#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n;
    cin>>n;
    int p=1000;
    while(p<n)
        p+=1000;
    cout<<p-n<<endl;
}
