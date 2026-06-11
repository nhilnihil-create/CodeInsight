#include<iostream>
#include<string>
#include<math.h>
#include<stdio.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    while (n != 0)
    {
        double a=0;
        double m = 0;
        int s[1000] = {0};

        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            m = m + s[i];
        }
        m= m/n;

        for(int i=0;i<n;i++)
        {
            a = a + pow((s[i]-m),2);
        }
        a = a/n;

        printf("%.5f\n",pow(a,0.5));

        cin>>n;
    }

    return 0;
}