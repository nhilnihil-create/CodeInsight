#include<bits/stdc++.h>
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        string s;
        cin>>s;
        vector<string>day(7);
        day[0]="SUN";
        day[1]="MON";
        day[2]="TUE";
        day[3]="WED";
        day[4]="THU";
        day[5]="FRI";
        day[6]="SAT";
        for(int j=0;j<7;j++){
                if(day[j]==s){
                        cout<<7-j;
                }
        }
        return 0;
}
/*

        creation time:  13.09.2020 09:23:27

*/                      

