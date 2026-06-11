#include<bits/stdc++.h>
using namespace std;

bool desc(const int a, const int b)
{
    return a > b;
}

int putere(int a, int b){
    int sol = 1;
    for(int i = 0 ; i < b ; i++){
        sol *= a;
    }
    return sol;
}

int main()
{
    int n;
    cin>>n;
    vector<int> s(putere(2, n));

    for(auto &x : s){
        cin>>x;
    }

    sort(s.begin(), s.end());

    int length = s.size();
    vector<int> resolved(length, 0);
    resolved[resolved.size() - 1] = 1;

    for(int i = 0 ; i < n ; i++){
        vector<int> parents;
        for(int k = 0 ; k < length ; k++){
            if(resolved[k])
                parents.push_back(s[k]);
        }
        for(int j = length - 1 ; j > -1 ; j--){
            if(parents[parents.size() - 1] > s[j] && resolved[j] == 0){
                resolved[j] = 1;
                parents.pop_back();
            }
            if(parents.size() == 0){
                break;
            }
        }
        if(parents.size() > 0){
            cout<<"No";
            return 0;
        }
    }

    cout<<"Yes";

    return 0;

}
