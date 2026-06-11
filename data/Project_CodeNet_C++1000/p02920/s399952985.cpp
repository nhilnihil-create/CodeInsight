#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    multiset <int> ms;
    for(int a,i=0; i<1<<n; i++){
        cin >> a;
        ms.insert(a);
    }

    vector <int> added{*prev(ms.end())};
    ms.erase(prev(ms.end()));
    for(int p=0; p<n; p++){
        for(int i=0; i<(1<<p); i++){
            auto it = ms.lower_bound(added[i]);
            if(it == ms.begin()){
                printf("No\n");
                return 0;
            }
            added.push_back(*prev(it));
            ms.erase(prev(it));
        }
    }
    printf("Yes\n");
}
