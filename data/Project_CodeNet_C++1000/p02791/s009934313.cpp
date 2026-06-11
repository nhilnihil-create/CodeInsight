#include <iostream>
using namespace std;

int main() {
	int a;
  scanf("%d",&a);int ar[a],c=1;
        for(int i=0;i<a;i++)
        scanf("%d",&ar[i]);
        for(int i=1;i<a;i++)
        ar[i]=min(ar[i],ar[i-1]);
        for(int i=1;i<a;i++)
        if(ar[i]!=ar[i-1])
        ++c;
        printf("%d",c);
	return 0;
}
