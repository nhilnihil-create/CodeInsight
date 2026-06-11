#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>
#include<bitset>
#include<string>
#include<utility>
#include<queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> w(n);
    vector<int> s(n+1);
    s.at(0)=0;
    int sum=0;
    int s1=0,s_2=0;
    for(int i=0;i<n;i++){
        cin >> w.at(i);
        sum+=w.at(i);
        s.at(i+1)=s.at(i)+w.at(i);
    }
    int ans=sum;
    int temp;
    for(int t=1;t<n;t++){
        temp =abs(s.at(t)-(sum-s.at(t)));
        if(ans>temp)ans=temp;
    }
    cout << ans << endl;
    return 0;
}