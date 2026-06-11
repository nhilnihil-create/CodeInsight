#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,j;
    long sum=0;

    cin >> n;

    vector<long> a(n+1),b(n);

    for(i=0; i<n+1; i++){
        cin >> a.at(i);
    }
    for(i=0; i<n; i++){
        cin >> b.at(i);
    }

    for(i=0; i<n; i++){
        if(a.at(i) > b.at(i))
            //街nの一部を退治
        {
            sum += b.at(i);
        }
        else if(a.at(i+1) > b.at(i) - a.at(i) )
            //街nを殲滅後、n+1の一部を退治
        {
                a.at(i+1) -= b.at(i) - a.at(i);
                sum += b.at(i);
        }
        else  //街n+1まで殲滅
        {
                sum += (a.at(i) + a.at(i+1));
                a.at(i+1) = 0;
        }
    }

    
    cout << sum << endl;
    
   return 0;
}