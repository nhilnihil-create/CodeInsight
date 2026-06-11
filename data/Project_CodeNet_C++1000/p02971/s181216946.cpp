#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i;
    cin >> n;

    vector<int> A(n);

    pair<int,int> one(0,0);
    int two;
    
    for(i=0; i<n; i++){

        cin >> A.at(i);
            if(one.first <= A.at(i)){
                two = one.first;
                one.first = A.at(i);
                one.second = i;
            }else if(two <= A.at(i)){
                two = A.at(i);
            }

    }

    for(i=0; i<n; i++){
        if(i == one.second){
            cout << two << endl;
            continue;
        }
        cout << one.first << endl;
    }

    return 0;
}