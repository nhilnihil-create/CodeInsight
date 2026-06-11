#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int GetDigit(unsigned long long num){
    return log10(num) + 1;
}

int main(){
    ll max = 1000000000000000001;
    int N;
    cin >> N;

    int keta1;
    int keta2;
    unsigned long long count;
    unsigned long long ai;
    vector<unsigned long long> A;
    int i;

    for(i=0;i<N;i++){
        cin >> ai;
        A.push_back(ai);
        if(ai==0){cout << 0 << endl; return 0;}
    }

    for(i=0;i<N;i++){
        ai = A[i];
        if(i==0){count=ai;continue;}
        keta1 = GetDigit(count);
        keta2 = GetDigit(ai);

        //cout << keta1 + keta2 - 2 << endl;
        if(((keta1 + keta2 - 2) == 17)){
            if(count * ai >= max){cout << "-1" << endl; return 0;}
        }
        else if((keta1 + keta2 - 2 ) == 18){
            if(count * ai != max - 1){cout << "-1" << endl; return 0;}
        }
        else if((keta1 + keta2 - 2) >= 19){cout << "-1" << endl; return 0;}
        count = count * ai;
    }

    cout << count << endl;

    return 0;
}
