#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> s((1<<n));
    for(int i=0; i<(1<<n); i++){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    //for(int slime : s) cout << slime << " ";
    //cout << endl;

    multiset<int> parents;
    parents.insert(s[0]);

    vector<int> already_generated((1<<n));
    already_generated[0] = 1;

    for(int i=0; i<n; i++){
        int slime = 0;
        auto itr = parents.rbegin();
        multiset<int> child;

        while(itr != parents.rend()){
            //cout << *itr << " ";
            while(already_generated[slime] == 1 || s[slime] >= *itr){
                slime += 1;

                if(slime == (1<<n)){
                    //for(int c : child) cout << c << " ";
                    //cout << endl; 
                    cout << "No" << endl;
                    return 0;
                }
            }
            child.insert(s[slime]);
            already_generated[slime] = 1;
            itr = next(itr);
        }
        //cout << endl;
        for(int c : child) parents.insert(c);
    }
    cout << "Yes" << endl;
    return 0;
}