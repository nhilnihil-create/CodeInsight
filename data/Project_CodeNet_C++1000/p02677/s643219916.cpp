//problem - S(indu)

#include <bits/stdc++.h>

#define rate_of_minute 6
#define rate_of_hour 30
#define hour_effected_by_minute 0.5
#define pi 3.1415926535897932384626433

int main()
{
    int a{0},b{0};
    int hour{0},minute{0};
    
    double gap{0.0000},angle_of_hour{0.0000},angle_of_minute{0.0000},C{0.000};
    
    scanf("%d %d %d %d",&a,&b,&hour,&minute);
    
    if(hour == 0 && minute == 0){
        gap = (double) a - b;
        if(gap < 0){
            gap *= (-1);
        }
        printf("%.20lf\n",gap);
        return 0;
    }
    
    angle_of_minute =(double) minute * rate_of_minute;
    angle_of_hour =(double) (hour * rate_of_hour) + (minute * hour_effected_by_minute);
    
    C = (double) angle_of_hour - angle_of_minute;
    if(C < 0){
        C *= (-1);
    }
    
    gap = (a * a) + (b * b) - (2 * a * b) * (cos(C * pi / 180.000));
    gap = sqrt(gap);
    
    printf("%.20lf\n",gap);
    
    return 0;
}