#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,fla=0;

    cin >> n;
    vector<int> h(n);

    cin >> h.at(0);

    for(i=1; i<n; i++){
        cin >> h.at(i);
        int k = h.at(i-1)- h.at(i);

        if(k >= 2){
            cout << "No" << endl;
            return 0;
        }else if(k == 1 && fla == 1){
            cout << "No" << endl;
            return 0;
        }else if(k == 1 && fla == 0){
            fla = 1;
        }else if(k < 0 && fla == 1){
            fla = 0;
        }
        
    }
    cout << "Yes" << endl;


    return 0;
}
