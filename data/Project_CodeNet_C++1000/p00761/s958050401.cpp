#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void)
{
	string s;
	int n;
	string smax,smin;
	int imax;
	int imin;

	int j;
	int ss;

	while(1){
		cin >> s >> n;
		if(s=="0" && n==0) break;

		while(s.size()<n){
			s += "0";
		}

		vector<string > a;
		vector<string>::iterator it;

		while(1){
			if(!a.empty()){
				it = find(a.begin(), a.end(),s);
				if(it!=a.end()) break;
			}
			//cout << s << endl;
			a.push_back(s);

			sort(s.begin(), s.end());
			smin = s;
			reverse(s.begin(), s.end());
			smax = s;

			/* string to int */
			istringstream istrmin(smin);
			istrmin >> imin;
			istringstream istrmax(smax);
			istrmax >> imax;

			/* int to string */
			ostringstream ostr;
			ostr << imax-imin;
			s = ostr.str();

			while(s.size()<n){
				s = "0" + s;
			}
		}

		j=it-a.begin();
		istringstream istr(s);
		istr >> ss;
		cout << j << " " << ss << " " << a.size()-j << endl;
	}

	return 0;
}