#include <iostream>
using namespace std;
int s;
long long f[2005];
const int mod=1e9+7;
/*
¿¼ÊÔµÄÊ±ºòÊ²Ã´¶¼ÏëÁË 
Ïë¹ý´ò±í£¨Ëã²»³ö±í£©Ïë¹ý×Ü·½°¸¼õ£¨Á¬×Ü·½°¸¶¼Ëã²»³öÀ´£© 
ÍòÍòÃ»Ïëµ½ÕâÊÇ¸ödp 
f[i]±íÊ¾°Ñi°´ÕÕÌâÒâ·Ö½âµÄ·½°¸ 
µ±i>=6Ê±£¬f[i]=sum(f[i-j])£¬3<=j<=i-3 
¾ÍÍêÁË 
*/ 
int main()
{
    cin>>s;
    if(s<3)
    {
    	cout<<0<<endl;
    	return 0;
	}
	for(int i=3;i<=s;i++)
	{
		f[i]=1;//Ö»ÓÐËü×Ô¼º 
		for(int j=3;i-j>=3;j++)
			f[i]=(f[i]+f[i-j])%mod;
	}
    cout<<f[s]<<endl;
    system("pause");
    return 0;
}