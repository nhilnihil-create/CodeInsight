#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
//#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll w[123456], x[123456], y[123456], z[123456], test[123];
signed main() {
	ll n, m, q, ans = 0, cnt = 0; cin >> n >> m >> q;
	for (int h = 0; h < q; h++) {
		cin >> w[h] >> x[h] >> y[h] >> z[h];
	}
	if (n == 1) {
		for (int a = 1; a <= m; a++) {
			test[0] = a;
			for (int h = 0; h < q; h++) {
				if (test[x[h] - 1] - test[w[h] - 1] == y[h]) {
					ans += z[h];
				}
			}
			cnt = max(cnt, ans); ans = 0;
		}
	}
	if (n == 2) {
		for (int a = 1; a <= m; a++) {
			test[0] = a;
			for (int b = a; b <= m; b++) {
				test[1] = b;
				for (int h = 0; h < q; h++) {
					if (test[x[h] - 1] - test[w[h] - 1] == y[h]) {
						ans += z[h];
					}
				}
				cnt = max(cnt, ans); ans = 0;
			}
		}
	}
	if (n == 3) {
		for (int a = 1; a <= m; a++) {
			test[0] = a;
			for (int b = a; b <= m; b++) {
				test[1] = b;
				for (int c = b; c <= m; c++) {
					test[2] = c;
					for (int h = 0; h < q; h++) {
						if (test[x[h] - 1] - test[w[h] - 1] == y[h]) {
							ans += z[h];
						}
					}
					cnt = max(cnt, ans); ans = 0;
				}
			}
		}
	}
	if (n == 4)	{
		for (int a = 1; a <= m; a++) {
			test[0] = a;
			for (int b = a; b <= m; b++) {
				test[1] = b;
				for (int c = b; c <= m; c++) {
					test[2] = c;
					for (int d = c; d <= m; d++) {
						test[3] = d;
						for (int h = 0; h < q; h++) {
							if (test[x[h] - 1] - test[w[h] - 1] == y[h]) {
								ans += z[h];
							}
						}
						cnt = max(cnt, ans); ans = 0;
					}
				}
			}
		}
	}
	if (n == 5) {
		for (int a = 1; a <= m; a++) {
			test[0] = a;
			for (int b = a; b <= m; b++) {
				test[1] = b;
				for (int c = b; c <= m; c++) {
					test[2] = c;
					for (int d = c; d <= m; d++) {
						test[3] = d;
						for (int e = d; e <= m; e++) {
							test[4] = e;
							for (int h = 0; h < q; h++) {
								if (test[x[h] - 1] - test[w[h] - 1] == y[h]) {
									ans += z[h];
								}
							}
							cnt = max(cnt, ans); ans = 0;
						}
					}
				}
			}
		}
	}
	if (n == 6) {
		for (int a = 1; a <= m; a++) {
			test[0] = a;
			for (int b = a; b <= m; b++) {
				test[1] = b;
				for (int c = b; c <= m; c++) {
					test[2] = c;
					for (int d = c; d <= m; d++) {
						test[3] = d;
						for (int e = d; e <= m; e++) {
							test[4] = e;
							for (int f = e; f <= m; f++) {
								test[5] = f;
								for (int h = 0; h < q; h++) {
									if (test[x[h] - 1] - test[w[h] - 1] == y[h]) {
										ans += z[h];
									}
								}
								cnt = max(cnt, ans); ans = 0;
							}
						}
					}
				}
			}
		}
	}
	if (n == 7) {
		for (int a = 1; a <= m; a++) {
			test[0] = a;
			for (int b = a; b <= m; b++) {
				test[1] = b;
				for (int c = b; c <= m; c++) {
					test[2] = c;
					for (int d = c; d <= m; d++) {
						test[3] = d;
						for (int e = d; e <= m; e++) {
							test[4] = e;
							for (int f = e; f <= m; f++) {
								test[5] = f;
								for (int g = f; g <= m; g++) {
									test[6] = g;
									for (int h = 0; h < q; h++) {
										if (test[x[h] - 1] - test[w[h] - 1] == y[h]) {
											ans += z[h];
										}
									}
									cnt = max(cnt, ans); ans = 0;
								}
							}
						}
					}
				}
			}
		}
	}
	if (n == 8) {
		for (int a = 1; a <= m; a++) {
			test[0] = a;
			for (int b = a; b <= m; b++) {
				test[1] = b;
				for (int c = b; c <= m; c++) {
					test[2] = c;
					for (int d = c; d <= m; d++) {
						test[3] = d;
						for (int e = d; e <= m; e++) {
							test[4] = e;
							for (int f = e; f <= m; f++) {
								test[5] = f;
								for (int g = f; g <= m; g++) {
									test[6] = g;
									for (int h = g; h <= m; h++) {
										test[7] = h;
										for (int h = 0; h < q; h++) {
											if (test[x[h] - 1] - test[w[h] - 1] == y[h]) {
												ans += z[h];
											}
										}
										cnt = max(cnt, ans); ans = 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (n == 9) {
		for (int a = 1; a <= m; a++) {
			test[0] = a;
			for (int b = a; b <= m; b++) {
				test[1] = b;
				for (int c = b; c <= m; c++) {
					test[2] = c;
					for (int d = c; d <= m; d++) {
						test[3] = d;
						for (int e = d; e <= m; e++) {
							test[4] = e;
							for (int f = e; f <= m; f++) {
								test[5] = f;
								for (int g = f; g <= m; g++) {
									test[6] = g;
									for (int h = g; h <= m; h++) {
										test[7] = h;
										for (int i = h; i <= m; i++) {
											test[8] = i;
											for (int h = 0; h < q; h++) {
												if (test[x[h] - 1] - test[w[h] - 1] == y[h]) {
													ans += z[h];
												}
											}
											cnt = max(cnt, ans); ans = 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (n == 10) {
		for (int a = 1; a <= m; a++) {
			test[0] = a;
			for (int b = a; b <= m; b++) {
				test[1] = b;
				for (int c = b; c <= m; c++) {
					test[2] = c;
					for (int d = c; d <= m; d++) {
						test[3] = d;
						for (int e = d; e <= m; e++) {
							test[4] = e;
							for (int f = e; f <= m; f++) {
								test[5] = f;
								for (int g = f; g <= m; g++) {
									test[6] = g;
									for (int h = g; h <= m; h++) {
										test[7] = h;
										for (int i = h; i <= m; i++) {
											test[8] = i;
											for (int j = i; j <= m; j++) {
												test[9] = j;
												for (int h = 0; h < q; h++) {
													if (test[x[h] - 1] - test[w[h] - 1] == y[h]) {
														ans += z[h];
													}
												}
												cnt = max(cnt, ans); ans = 0;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << cnt << endl;
	cin >> n; return 0;
}