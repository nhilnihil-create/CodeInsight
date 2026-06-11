//                               //
    // author : samars_diary //
    // 17-09-2020 │ 08:08:58 //
//                               //

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    long long int AC(0),TLE(0),WA(0),RE(0);
    string temp;
    while(t--){
        cin>>temp;
        if(temp=="AC"){
            AC+=1;
        }else if(temp=="TLE"){
            TLE+=1;
        }else if(temp=="WA"){
            WA+=1;
        }else{
            RE+=1;
        }
    }
    cout<<"AC x "<<AC<<'\n';
    cout<<"WA x "<<WA<<'\n';
    cout<<"TLE x "<<TLE<<'\n';
    cout<<"RE x "<<RE<<'\n';
    return 0;
}