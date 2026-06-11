#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	int i1,i2;
	int nn;
	int min;
	int num;
	int max;
	vector<int> v;
	
	

	max=0;

	while(1){
		cin >> n;
		if(n==0) break;
		if(max<n) max=n;
		v.push_back(n);
		
	}

	vector<int> pollock(max+1,0);
	vector<int> pollock2(max+1,0);
	vector<int> p;
	vector<int> p2;
	nn=1;
	num=(nn*(nn+1)*(nn+2))/6;

	for(i1=1;i1<=max;i1++){			

		if(i1==num) {
			if(i1%2==1){
				p.push_back(i1);
				p2.push_back(i1);
				nn++;
				num=(nn*(nn+1)*(nn+2))/6;
				pollock[i1]=1;
				pollock2[i1]=1;
			}
			else {
				nn++;
				num=(nn*(nn+1)*(nn+2))/6;
				p.push_back(i1);
				pollock[i1]=1;
				min=100000;
				for(i2=0;i2<p2.size();i2++){
					if((pollock2[i1-p2[i2]])<min){
						min=pollock2[i1-p2[i2]];
					}
				}
				pollock2[i1]=min+1;
			}
		}
		else {
			min=100000;
			for(i2=0;i2<p.size();i2++){
				if((pollock[i1-p[i2]])<min){
					min=pollock[i1-p[i2]];
				}
			}
			pollock[i1]=min+1;

			min=100000;
			for(i2=0;i2<p2.size();i2++){
				if((pollock2[i1-p2[i2]])<min){
					min=pollock2[i1-p2[i2]];
				}
			}
			pollock2[i1]=min+1;
		}
			//cout<<pollock[i1]<<" ";
	}

	for(i1=0;i1<v.size();i1++){

		cout << pollock[v[i1]] << " " << pollock2[v[i1]] << endl;
	}


	return 0;
}