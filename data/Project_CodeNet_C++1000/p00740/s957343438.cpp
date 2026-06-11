#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define pb push_back

ll MIN(ll num1,ll num2){
    return num1<num2?num1:num2;
}

int main(){

    while(1){
        int n,p;
        cin>>n>>p;
        if(n==0&&p==0)break;
        //cout<<n<<" "<<p<<endl;
        vector<int> stone;
        for(int i=0;i<n;i++)stone.pb(0);
        int now=0;
        while(1){
            if(p==0){
                p=stone[now];
                stone[now]=0;
            }else{
                p--;
                stone[now]++;
            }

            bool flag=true;
            for(int i=0;i<n;i++){
                if(i==now)continue;
                if(stone[i]!=0)flag=false;
            }
            if(p==0&&flag){
                cout<<now<<endl;
                break;
            }

            now++;
            if(now>=n)now=0;
        }
    }

    return 0;
}
