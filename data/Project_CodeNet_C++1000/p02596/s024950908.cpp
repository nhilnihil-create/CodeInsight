#include<bits/stdc++.h>

using namespace std;

int main(){
    int k;cin>>k;
    long long val=7;
    val=val%k;
    for(int i=1;i<=k;i++){
        if(val==0){
            cout << i <<endl;
            return 0;
        }
        val=(val*10+7)%k;
    }
    cout <<-1<<endl;
}
