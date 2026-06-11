#include <bits/stdc++.h>

using namespace std;

int digit_sum(unsigned long long xx){
    int dd = 0;
    string xx_string = to_string(xx);
    int len = xx_string.length();
    for(int i=0; i<len; ++i){
        dd += xx_string[i] - '0';
    }
    return dd;
}

int main(){
    unsigned long long M;
    cin>>M;
    vector<unsigned long long> d(M), c(M);
    for(int i=0; i<M; ++i){
        cin>>d[i]>>c[i];
    }

    unsigned long long ans = 0;
    stack<int> a;
    for(int i=0; i<M; ++i){
        unsigned long long x = d[i] * c[i];
        ans += c[i] - 1;
        if(x>1){
            ans += (x - 1) / 9;
        }
        while(x>=10){
            x = digit_sum(x);
        }
        a.push(x);

        while(a.size()>1){
            int aa = a.top();
            a.pop();
            int bb = a.top();
            a.pop();

            int sum = aa + bb;
            if(sum < 10){
                a.push(sum);
            }else{
                a.push(1);
                a.push(sum-10);
            }
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}