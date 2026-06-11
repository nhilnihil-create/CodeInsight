#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
//#define debug
#define MP make_pair
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
const int le5=1e5;
int x,y;
int A,B,C;
int a[le5+10],b[le5+10],c[le5*3+10];
bool cmp(int a,int b){return a>b;}
int main()
{
	scanf("%d%d",&x,&y);
	scanf("%d%d%d",&A,&B,&C);
	
	for(int i=1; i<=A; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=B; i++)
		scanf("%d",&b[i]);
	for(int i=1; i<=C; i++)
		scanf("%d",&c[i]);
	
	sort(a+1,a+1+A,cmp);
	sort(b+1,b+1+B,cmp);

	for(int i=1; i<=x; i++)
		c[C+i]=a[i];
	for(int i=1; i<=y; i++)
		c[C+x+i]=b[i];
		
	sort(c+1,c+1+C+x+y,cmp);
	
	#ifdef debug
	//一维数组打表
	printf("A:\n");
	for(int i=1; i<=C+x+y; i++)
		printf("%3d",i);
	printf("\n");
	for(int i=1; i<=C+x+y; i++)
		printf("%3d",c[i]);
	printf("\n");
	#endif
	ll sum=0;
	for(int i=1; i<=x+y; i++)
		sum+=c[i];
	printf("%lld\n",sum);
	
//	#ifdef debug
//	//一维数组打表
//	printf("A:\n");
//	for(int i=1; i<=A; i++)
//		printf("%3d",i);
//	printf("\n");
//	for(int i=1; i<=A; i++)
//		printf("%3d",a[i]);
//	printf("\n");
//	#endif
//	
//	int pa=1,pb=1,pc=1;
//	ll sum=0;
////	while(pa<=A&&pb<=B&&pa+pb+pc<=A+B)
//	while(pa+pb+pc<=x+y+2)
//	{
//		if(pa<=x
//		&&a[pa]>=b[pb]&&a[pa]>=c[pc]
//		)
//		{
//			
//			sum+=a[pa];
//			pa++;
//		}
//		else
//		{
//			if(pb<=y
//			&&b[pb]>=a[pa] && b[pb]>=c[pc])
//			{
//				sum+=b[pb];
//				pb++;
//			}
//			else
//			{
//				
//				if(c[pc]>=a[pa] && c[pc]>=b[pb])
//				{
//					sum+=c[pc];
//					pc++;
//				}
//				else
//				{//有不足的
//					if(pa>x)
//					{
//						if(b[pb]<=c[pc])
//						{
//							sum+=c[pc];
//							pc++;
//						}
//						else
//						{
//							sum+=b[pb];
//							pb++;
//						}
//					}
//					else
//					{
//						if(pb>y)
//						{
//							if(a[pa]<=c[pc])
//							{
//								sum+=c[pc];
//								pc++;
//							}
//							else
//							{
//								sum+=a[pa];
//								pa++;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	
//	
//	printf("%lld\n",sum);
	return 0;
}
/*

*/