#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int N;
    set<string> prise;
    int count = 0;


    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        
        if(prise.find(s)==prise.end()){
            prise.insert(s);
        }
    }
    cout << prise.size() << endl;


        return 0;
}
