#include<iostream>
main(){int y,m,d;for(std::cin>>d;std::cin>>y>>m>>d;printf("%d\n",196685-d))d+=195*y+19*m+(y-1)/3*5+(y%3?m/2:m-1);}