#include <string.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

#define ll (long lon
#define REP(i,n) for(int i = 0;i<(int)n;i++)
#define FOR(i,a,b) for(int i = (a);i < (b);i++)
#define RFOR(i,a,b) for(int i = (a);i>(b);i--)
#define INT_MIN_A -999999

using namespace std;

int main (void){
    
    char str[2001];
    gets(str);
    char tango[1000][33];
    int i = 0,j = 0,k = 0,l = 0, temp = 0,m = 0;
    int max_l = INT_MIN_A;
    int max_numer = 0;
    int yokuderu = 0;
    int yokuderu_temp = 0;
    int yokuderu_number = 0;
    while(str[i++] != '\0')
    {
        if(str[i-1] == ' ')
        {
            if((i-1)-temp>max_l)
            {
                max_l = (i-1) -temp;
                max_numer = j;
            }
            while(temp<i-1)
                tango[j][l++] = str[temp++];
            temp = i;
            j++;
            l = 0;
        }
    }
    
 
        if((i-1)-temp>max_l)
        {
            max_l = (i-1) -temp;
            max_numer = j;
        }
        while(temp<i-1)
            tango[j][l++] = str[temp++];
        temp = i;
        j++;
        l = 0;
    /*???????????§??????????????????*/
    //cout <<"number is " << j << endl;
    
    for(int m = 0; m < j;m++)
    {
        for(int k = 0; k<j;k++)
        {
            if(m != k)
            {
                if(strcmp(tango[m], tango[k]) == 0)
                {
                    yokuderu_temp++;
                }
            }
        }
        if(yokuderu_temp >= yokuderu)
        {
            yokuderu = yokuderu_temp;
            yokuderu_number = m;
        }
        yokuderu_temp = 0;
    }
    cout << tango[yokuderu_number] << " " << tango[max_numer] << endl;
    return 0;
}