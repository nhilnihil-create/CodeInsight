#include<iostream>
#include<set>

using namespace std;

int main(){
    int N;
    cin >> N;
    int loc[N];
    
    int p;
    for(int i=0; i<N; i++){
        cin >> p;
        p--;
        loc[p] = i;
    }

    multiset<int> ms{-1, -1, N, N};

    long w, x, y, z;
    long ans = 0;

    for(long i = N-1; i >= 0; i--){
        ms.insert(loc[i]);
        auto itr = ms.find(loc[i]);
        auto itr2 = itr;

        x = *(--itr);
        w = *(--itr);
        y = *(++itr2);
        z = *(++itr2);

        ans += (i+1) * ((x-w) * (y-loc[i]) + (loc[i]-x) * (z-y));

    }

    cout << ans << endl;

    return 0;
}