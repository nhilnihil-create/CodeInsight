#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    int sum=0;
    int last;
    int chk;
    int bef,cur,aft;
    cin >> N;

    vector<int> w(N);

    for(int i=0;i<N;i++) {
        cin >> w[i];
        sum += w[i];
    }

//    sort(w.begin(), w.end());

    chk = sum/ 2;
    last = 0;
        bef = INT_MAX;
        aft = INT_MAX;
    for(int i=0;i<N;i++){
        w[i] += last;
        last = w[i];
        if(w[i] >= chk){
            if(i) bef=sum-(2*w[i-1]);
            cur = sum-(2*w[i]);
            if(i<N-1) aft = sum-((w[i]+w[i+1])*2);
//printf("bef:%d cur:%d aft:%d\n", bef, cur,  aft);
            cout << min(abs(bef),min(abs(cur),abs(aft))) << endl;
            break;
        }
    }

    return 0;
}
