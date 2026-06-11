#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    int pay=(int)ceil(n/1000.0);
    cout << (pay*1000) - n<<endl;
}
