#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int i;
    int vote = 0;
    int count=0;
    for(i=0;i<n;i++){
        cin >> a.at(i);
        vote += a.at(i);
    }

    for(i=0;i<n;i++){
        if(a.at(i) >= vote/(4.0*m))
            count++;
    }

    if(count>=m)
        cout << "Yes" << endl;
    else
    {
        cout << "No" << endl;
    }
    
}