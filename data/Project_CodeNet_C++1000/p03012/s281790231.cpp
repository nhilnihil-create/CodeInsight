#include<bits/stdc++.h>
using namespace std;

int main(){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0;i< n;i++)
        {
                cin >> arr[i];
        }
        int ans = 1000000;
        int s_1=0;
        int s_2 = 0;
        for(int i = 1;i<= n;i++)
        {
                for(int j= 0;j<i;j++)
                {
                        s_1+=arr[j];
                }
                for(int j = i;j<n;j++)
                {
                        s_2 += arr[j];
                }
                ans = min(ans, abs(s_1-s_2));
          		s_1 = 0;
          		s_2 = 0;
        }
        cout <<ans<< endl;
}